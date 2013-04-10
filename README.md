*Zolver*
========

*Zolver* is a *Robozzle* puzzle solver. It reads level files and outputs the
computed solution.

The current version is still in development, which means that for the sake of
comparison, each level is computed four times. This is used to compare
optimized solvers to their brute-force counterparts.

Optimizations
-------------

In its current state, *Zolver* does nothing more than generating all possible
programs and run them. A few optimizations are made in order to hasten a bit
the computation:

  * Loop detection: when pushing a function on the stack, a quick comparison is
    made against previous game states. Functions being parameter-less and
    deterministic, if a previous call to the same function was made with the
    same state, then the program is in a infinite loop.

  * Post-call elimination: functions in which there is a unmissable call (a
    call to a function without color condition), then all remaining
    instructions can't be anything else than "noop".

  * Post-paint elimination: until the next valid movement or function call,
    instructions after a paint call can be restricted to the subset of colours
    that remain.

  * Roundabout elimination: successive "turn" calls are detected and avoided.

A major optimization that still needs to be done would be to make "Tester"
classes stateless and use a thread pool to test several potential solutions at
the same time.

Known issues
------------

  * The *better tester* might report some valid programs as failures, due to
    over-zealous stack loop detection (you might try `green.rbz` if you have a
    few spare hours).

  * The *better solver* will probably not find the most concise
    solution. `faster_naive.rbz` is an illustration of this problem. This one,
    however, might be an easy fix.

  * The thread pooling upgrade is not yet implemented.

Usage
-----

``` bash
./configure
make
./bin/zolver levels/test.rbz
```

File format
-----------

All values in a file are separated by any kind of whitespace; comments run from `#` to
the end of the line. See `levels/test.rbz` for a commented example.

