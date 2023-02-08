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

