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

### Immutability

In order to update values immutably, your code must make copies of existing
objects/arrays, and then modify the copies. React expects that all state updates
are done immutably.

### Terminology

1. Actions: An action is a plain JavaScript object that has a `type` field. You
  can think of an action as an event that describes something that happened in
  the application.
2. Action Creators: An action creator is a function that creates and returns an
  action object.
3. Reducer: A reducer is a function that receives the current `state` and an
  `action` object, decides how to update the state if necessary, and returns the
  new state: `(state, action) => newState`. You can think of a reducer as an
  event listener which handles events based on the received action type.
4. Store: The current Redux application state lives in an object called the
  store.
5. Dispatch: The only way to update the state is to call `store.dispatch()` and
  pass in an action object.
6. Selectors: Selectors are functions that know how to extract specific pieces
  of information from a store state value. As an application grows bigger, this
  can help avoid repeating logic as different parts of the app need to read the
  same data.

