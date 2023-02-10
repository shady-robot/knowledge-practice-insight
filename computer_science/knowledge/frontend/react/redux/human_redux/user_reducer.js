/*
 * get_metadata_reducer.js
 *
 */

// just using the file we defined above
import getMetadataReducer from './get-metadata-reducer'
import { createStore, combineReducers } from 'redux'

const generatedReducer = getMetadataReducer({
  baseType: 'FETCH_USERS'
})

// we will write our own reducer here
const userReducer = (state, action) => {
  // we can just pass our state and action
  // through the generated reducer first.
  state = generatedReducer(state, action)

  if (action.type === 'SOME_OTHER_ACTION') {
    return Object.assign({}, state, {
      otherThing: true
    })
  }

  return state
}

const store = createStore(
  combineReducers({
    usersReducer
    // ...
    // ... other reducers
    // ...
  })
)
