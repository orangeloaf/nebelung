# nebelung
Exotic game engine using a tech stack of C + SDL + Lisp + Emscripten

The project name refers to the breed of [long-haired grey cat](https://en.wikipedia.org/wiki/Nebelung).

# git-fu
Some git tricks were used to create this repo. It is overkill, but I wanted the full source of the tools and libs in the tech stack to be available as part of the project, for posterity's sake.

Dependency projects were added as remotes:

	git remote add tinycc http://repo.or.cz/tinycc.git
	git remote add femtolisp https://github.com/JeffBezanson/femtolisp.git
	git remote add sdl https://github.com/spurious/SDL-mirror.git

The remotes were fetched:

	git fetch tinycc
	git fetch femtolisp
	git fetch sdl

Branches were created:

	git checkout -b tinycc tinycc/master
	git checkout -b femtolisp femtolisp/master
	git checkout -b sdl sdl/master
	git checkout master

Subdirectories were added:

	git read-tree --prefix=remote/tinycc tinycc
	git read-tree --prefix=remote/femtolisp femtolisp
	git read-tree --prefix=remote/sdl sdl

And of course committed (one at a time):

	git checkout -- .
	git commit

For more on this git topic, see
https://git-scm.com/book/en/v1/Git-Tools-Subtree-Merging

# Building with tinycc

Hacks needed to compile are noted here in brief, gorey details are in the repo history.

- Some customizations were made in remote/femtolisp
-- Makefile set CC = tcc
-- llt/dtypes.h if defined __TINYC__ then define __SIZEOF_POINTER__ 8
-- llt/utils.h if defined __TINYC__ then define ARCH_X86 and __CPU__ 686
- MinGW libs and includes had to be added to TinyCC
-- winsock2.h copied from gcc/include to tinycc/include
- "unknown constraint t" bug in math.h
-- fix to i386-asm.c, [patch found here](https://lists.nongnu.org/archive/html/tinycc-devel/2014-08/msg00024.html)

# Building with gcc

Although building with TinyCC is the goal, building with gcc should also be supported.

For Windows users, MinGW + MSYS is a good setup for this.
