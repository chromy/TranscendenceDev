# Contributing to the clang build of Transcendence

If you wish to contribute to the official Transcendence repository see [here](https://github.com/kronosaur/TranscendenceDev).

If you wish to contribute to the clang build of Transcendence here are some valuable tasks which would help the effort:
- [Upstreaming required code changes](#upstreaming)
- [Resolving clang TODOs](#resolving-todos)


## Upstreaming

A small number of code changes (`48 files changed, 283 insertions(+), 259 deletions(-)` at time of writing)
were required to get the clang build working.
These are mainly a mixture of
- small tweaks for things that clang can't handle that MSVC can handle
- fixing case mismatches which cause issues on case-sensitive file systems

The delta between the clang build sourcecode and the official sourcecode
can be seen by doing:
```
git diff --stat master clang '*.cpp' '*.h' '*.rc' '*.jpg' '*.JPG' '*.BMP' '*.bmp'
```

One valuable thing would be reduce the diff between this repo and the official repo
by opening PRs either in the official repo (to adopt parts of the diff) on in this
repo (to make the changes less invasive).

## Resolving TODOs

Clang specific TODOs are in the codebase and look like this:
```
TODO(clang): Fix some thingy
```

To see all of the TODOs run:
```
git grep -n 'TODO(clang)'
```

One valuable thing would be to resolve a TODO.

