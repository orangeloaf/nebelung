# nebelung
Exotic game engine using a tech stack of C + SDL + Lisp + Emscripten

# git-fu
Some git tricks were used to create this repo:

- Dependency projects were added as remotes
$ git remote add tinycc http://repo.or.cz/tinycc.git
$ git remote add femtolisp https://github.com/JeffBezanson/femtolisp.git

- The remotes were fetched
$ git fetch tinycc
$ git fetch femtolisp

- Branches were created
$ git checkout -b tinycc tinycc/master
$ git checkout -b femtolisp femtolisp/master
$ git checkout master

- Subdirectories were added
$ git read-tree --prefix=remote/tinycc tinycc
$ git read-tree --prefix=remote/femtolisp femtolisp

- And of course committed (one at a time)
$ git commit

# Project Name
It refers to the breed of long-haired grey cat.
