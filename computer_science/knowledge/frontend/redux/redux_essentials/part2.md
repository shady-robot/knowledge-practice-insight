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

## Async Logic and  Data Fetching

By default, a Redux store doesn't know anything about async logic. It only knows
how to synchronously dispatch actions, update the state by calling the root
reducer function, and notify the UI that something has changed.

The `Redux middleware`:

* Execute extra logic when any action is dispatched
* Pause, modify, delay, replace, or halt dispatched action
* Write extra code that has access to `dispatch` and `setState`
* Teach `dispatch` how to accept other values besides plain action objects, such
  as functions and promises, by intercepting them and dispatching real action
  object instead

The most common async middleware is `redux-thunk`, which lets you write plain
functions that may contain async logic directly. Redux Toolkit's
`configureStore` function automatically sets up the thunk middleware by default,
and we recommend using thunks as a standard approach for writing async logic
with Redux.

```js
const logAndAdd = amount => {
    return (dispatch, getState) => {
        const stateBefore = getState()
        cosnole.log(`Counter before: ${stateBefore.counter}`)
        dispatch(incrementByAmount(amount))
        const stateAfter = getState()
        console.log(`Counter after: ${stateAfter.counter}`)
    }
}
```

Thunks are typically written in "slice" files, which normally as a separate
functions in the same slice file. That way, they have to access to the plain
action creators for that slice, and it's easy to find where the thunk lives.

You can dispatch additional actions to help track the loading status of an API
call. The typical pattern is dispatching a "pending" action before the call,
then either a "success" containing the data or a "failure" action containing the
error. Loading state should usually be stored as an enum, like `"idle" |
"loading" | "succeeded" | "failed"`.

### createAsyncThunk

```js
export const fetchPosts = createAsyncThunk('posts/fetchPosts', async () => {
  const response = await client.get('/fakeApi/posts')
  return response.data
})

const postsSlice = createSlice({
  name: 'posts',
  initialState,
  reducers: {
    // omit existing reducers here
  },
  extraReducers(builder) {
    builder
      .addCase(fetchPosts.pending, (state, action) => {
        state.status = 'loading'
      })
      .addCase(fetchPosts.fulfilled, (state, action) => {
        state.status = 'succeeded'
        // Add any fetched posts to the array
        state.posts = state.posts.concat(action.payload)
      })
      .addCase(fetchPosts.rejected, (state, action) => {
        state.status = 'failed'
        state.error = action.error.message
      })
  }
})
```

Redux Toolkit has a `createAsynThunk` API that dispatches these actions for you.

* `createAsynThunk` accepts a "payload creator" callback that should return a
  Promise, and generates `pending/fulfilled/rejected` action types automatically
* Generated action creators like `fetchPosts` dispatch those actions based on
  the `Promise` you return.
* You can listen for these action types in `createSlice` using the
  `extraReducers` field, and update the state in reducers based on those actions
* Action creators can be used to automatically fill in the keys of the
  `extraReducers` object so the slice knows what actions to listen for.
* Thunks can return promises. For `createAsynThunk` specially, you can `await
  dispatch(someThunk()).unwrap()` to handle the request success or failure at
  the component level

### Selectors

It's often a good idea to encapsulate data lookups by writing reusable selectors
. You can also create "memorized" selectors that can help improve performance.

