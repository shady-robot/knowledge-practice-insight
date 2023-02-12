# Redux Patterns

## Decoupling views from data fetching

Good PWAs cache more than just the "application shell"(the code required to run
the UI). They should also be caching the data fetched in the course of using the
app. That way, if you open it while you're offline, it will at least show you
the content it last has while trying to update.

In the context of a PWA, you want to make that app have a life of its own,
regardless of the current internet connection. Doing this often involves
explicitly managing locally cached data separate from the UI logic in your app.

## Routing with Redux

## Reactors

Reactors are special selectors that check for certain conditions, and if those
conditions are met, they can dispatch other actions.

1. We need somehow "register" these reactors to be evaluated regularly.
2. Each reactor needs to be evaluated after each action, much like what
  `connect()` does. So something needs to subscribe to the store and run all the
  reactors and dispatch any results.
3. A reactor needs to be able to somehow cause an action to be dispatched.
4. The reactors should either return something "falsy", like "null" or just not
  return at all(undefined). Or they should return something dispatch-able, which
  would be a plain action object, or the result of calling an action creator.

```js
import { createSelector } from "reselect"

const sampleReactor = createSelector(
    selectSomething,
    selectSomethingElse,
    (something, somethingElse) => {
        if(something && somethingElse) {
            return ( type: "SOMETHING_HAPPENED")
        }
    }
)
```

Whenever you use the current state to trigger a dispatch you increase the risk
of creating loops. To avoid loops when using this pattern, we must ensure that
the action that our reactor returns will immediately cause a state change that
the reactor checks for. If not, you'll have infinite loops.

### Redux is beautiful the way it is

Letting our state inform what should happen next grants us significantly more
power than writing procedures that should occur in response to specific actions.

## Reliable apps

If we want to build trust with our users, it is downright irresponsible for us
to assume we'll always have a fast, reliable connection.

 A robust solution:

1. Retry if there were network errors
2. Give up if there were "permanent" failures such as the user blocking
  geolocation.
3. Persist any time it succeeded and automatically pick up where it left off.
4. Automatically determine what to do next based on how long it had been.



