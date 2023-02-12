# Redux

Redux is a pattern and library for managing and updating application state,
using events called "actions". It serves as a centralized store for state that
needs to be used across your entire application, with rules ensuring that the
state can only be updated in a predictable fashion.

## Redux Libraries and Tools

* React-Redux: Official package that lets your React components interact with a
  Redux store by reading pieces of state and dipatching actions to update the
  store.
* Redux Toolkit: Contains packages and functions that we think are essential for
  building a Redux app.
* Redux DevTools Extension: Shows a history of the changes to the state in your
  Redux store over time

## Redux Terms and Concepts

### State Management

* The state, the source of truth that drives our app
* The view, a declarative description of the UI based on the current state.
* The actions, the events that occur in the app based on user input, and trigger
  updates in the state.

![One-way data flow](./images/one-way-data-flow.png)


