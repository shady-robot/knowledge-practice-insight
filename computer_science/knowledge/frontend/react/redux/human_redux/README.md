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
