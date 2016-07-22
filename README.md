# nebelung
Exotic game engine using a tech stack of C + SDL + Lisp + Emscripten

# git-fu
Some git tricks were used to create this repo. It is overkill, but I wanted the full source of the tools and libs in the tech stack to be available as part of the project, for posterity's sake.

- Dependency projects were added as remotes
$ git remote add tinycc http://repo.or.cz/tinycc.git
$ git remote add femtolisp https://github.com/JeffBezanson/femtolisp.git
$ git remote add sdl https://github.com/spurious/SDL-mirror.git

- The remotes were fetched
$ git fetch tinycc
$ git fetch femtolisp
$ git fetch sdl

- Branches were created
$ git checkout -b tinycc tinycc/master
$ git checkout -b femtolisp femtolisp/master
$ git checkout -b sdl sdl/master
$ git checkout master

- Subdirectories were added
$ git read-tree --prefix=remote/tinycc tinycc
$ git read-tree --prefix=remote/femtolisp femtolisp
$ git read-tree --prefix=remote/sdl sdl

- And of course committed (one at a time)
$ git checkout -- .
$ git commit

For more on this git topic, see
https://git-scm.com/book/en/v1/Git-Tools-Subtree-Merging

# Project Name
It refers to the breed of long-haired grey cat.
