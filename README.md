# My CPP monorepo! [![Ubuntu Make Compile](https://github.com/lithiumox-codam/CPP/actions/workflows/make.yml/badge.svg)](https://github.com/lithiumox-codam/CPP/actions/workflows/make.yml)

[![](https://tokei.rs/b1/github/lithiumox-codam/CPP?category=code&type=CPP&label=Lines%20of%20CPP)](https://github.com/lithiumox-codam/CPP)
[![](https://tokei.rs/b1/github/lithiumox-codam/CPP?category=files&type=Makefile&label=Number%20of%20Makefiles)](https://github.com/lithiumox-codam/CPP)

This is my CPP monorepo. It does some cool stuff like implement clang tooling and a global makefile to build all the things. It will contain all the CPP projects I need to do in the 42 curriculum.

## How to build

First off there are some dependencies you need to install.
 - ![](https://github.com/rizsotto/Bear) (for generating compile_commands.json)
 - ![](https://clang.llvm.org/) (for clang-tidy and clang-format)
 - ![](https://clang.llvm.org/extra/clang-tidy/) (for static analysis)
 - ![](https://clang.llvm.org/docs/ClangFormat.html) (for formatting)

 After you have installed these dependencies, you can build the project by running the following command in the root of the project:

```bash
make
```

Yes, that's it. It will build all the things. If you do want to build a specific part of the project, you can do so by going to that directory and running `make` there.

## How to run

First go to the directory of the project you want to run, then run the executable.

Example:
```bash
cd 00/ex00
./megaphone
```

## Contributing to this project

Unfortunately, this project is not open to contributions. It is a school project and I am not allowed to accept contributions from other people. However, if you do find a bug, feel free to open an issue and I will try to fix it as soon as possible. This helps me learn to be a better programmer. So thanks in advance!
