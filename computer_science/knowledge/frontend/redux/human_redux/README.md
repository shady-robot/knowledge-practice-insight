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

## Actions and reducers

An "action" in Redux terms is simply "a thing that happened" expressed as a
plain Javascript Object. They don't describe intent, they describe facts that
happened.

* Keep writing action types past-intense.
* Actions are like reports. Only report what matters, only report the facts.
* The recepient, not the sender determines how a given report affects the state.
* Actions often have a payload of some type. Try to attaching additional details
  about the action as a property called `payload`.

## Action creators

An action creator is a function that literally creates an object. In Redux,
action creators simply return an action object and pass the argument value if
necessary.

```js
const changeWheel = (payload) => {
    return {
        type: "CHANGE_WHEEL",
        payload
    }
}
```

`bindActionCrator` is a utility that takes an action creator(or a while object
of action creators) and binds them all to the `dispatch` function you got from
a store.

Refer to [bindActionCreator example](./action_creator_bind.js).

## Middleware and store enhancers

1. A store enhancer, enhances or adds additional capabilities to the store. It
  could change how reducers process data, or how dispatch works.
2. Middleware is a function that lets up "tap into" what's happening inside
  Redux when we dispatch an action.

```js
// createStore(reduccer, preloadState, enhancer)
import { createStore, applyMiddleware } from 'redux'
import rootReducer from './reducers'
import reduxLogger from 'redux-logger'
import reduxThunk from 'redux-thunk'

const store = createStore(rootReducer, applyMiddleware(reduxLogger, reduxThunk))

// Example of middleware

const loggingMiddleware = store => next => action => {
  console.log('action:', action)
  const result = next(action)
  console.log('state after action:', store.getState())
  return result
}
```

## Using state in your views

The Provider take the Redux `store` that you give as a property and will put it
into React's `context` API so that it can be available to any component rendered
inside the `<Provider>` that needs access to the store.

The basic idea of `connect()` is quite simple: connect a given component in a
way that allows it access the store. The `<Provider>` puts the store into
`context`, `connect()` gets some stuff from the store. It lets you connect
relevant state that your component may need from the store and handles
re-rendering the component if any of that "connected state" changes.

## Selectors

A selector is a function that takes the current application state and return the
relevant portion needed by the view. Selector let us ask question of our state.
Think of our application state as a database, we could say if action cause
"write" to the database, selectors are how we do "reads" from the database.

```js
const selectPagesOfResults = appState => {
    const {results} = appState
    if(!results|| !results.length) {
        return 0
    }
    return MAth.ceil(results.length / 20)
}
```

A common mistake is to try to calculate and store this derived data as part of
the application state. An excellent way to tell if you're doing this is if
you're finding yourself writing a reducer that updates a derived value as part
of handling a specific action. It's pretty safe to say you should probably be
using a selector to read that derived value instead.

Only dispatch things that are actually "newsworthy", because there's potentially
a lot of code that will be re-evaluated with each dispatch.

By isolating these pieces of logic into small, simple, pure functions that just
returned an answer to a specific question we were able to reduce the complexity
of the components in the app dramatically. Components were no longer responsible
for encapsulating application logic, they merely has to be connected to the
right selectors.

Reselect lets us derive increasingly complex answers while containing complexity
. These patterns allow us to efficiently answer incredibly complex questions of
our state by isolating chunks of logic into their separate selectors.

