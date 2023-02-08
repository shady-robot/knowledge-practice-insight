# Human Redux

Hardest problems for web developer:

1. Managing complexity of your code base as it grows and as requirements shift
2. Managing application state

State management is the hardest problem building UI applications.
React or similar rendering approaches let us conceptually dump-down the entire
application into the following bit of pseudo-code.

`UI = view(state)`

Redux is a pattern for storing, updating, and reading application state outside
of your components.

Why we need Redux?

1. It provides a set of patterns and conventions for building applications that
  work this way.
2. Having a single object containing all of our application state can become
  unwieldy as it grows. Redux provides a way to slice this state into more
  manageable chunks.
3. Redux offers a structured approach for how to go about making updates to
  state.

