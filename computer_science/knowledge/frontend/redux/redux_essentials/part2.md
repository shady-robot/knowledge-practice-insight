# Redux Essentials

Normally action object just contains the minimum amount of information needed to
describe what happened. It's always better to keep the action objects as small
as possible, and do the state update calculations in the reducer. This also
means that reducers can contain as much logic as necessary to calculate the new
state.

1. Any React component can use data from the Redux store as needed.
  * Any component can read any data that is in the Redux store.
  * Multiple components can read the same data, even at the same time.
  * Components should extract the smallest amount of data they need to render
    themselves
  * Components can combine values from props, state, and the Redux store to
    determine what UI they need to render. They can read multiple pieces of data
    from the store, and reshape the data as needed for display.
  * Any component can dispatch actions to cause state update.

2. Redux action creators can prepare action objects with the right contents.
  * `createSlice` and `createAction` can accept a "prepare callback" that
    returns the action payload
  * Unique IDs and other random values should be put in the action, not
    calculated in the reducer.
3. Reducers should contain the actual state update logic
  * Reducer can contain whatever logic is needed to calculate the next state.
  * Action objects should contain just enough info to describe what happened.

