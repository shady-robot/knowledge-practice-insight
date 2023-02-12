/*
 * reducer_lookup_tables.js
 *
 */
const cases = {
    SEARCH_STARTED: (state, action) =>
      Object.assign({}, state, {
        query: action.payload,
        fetching: true
      }),
    SEARCH_COMPLETED: (state, action) => 
      Object.assign({}, state, {
        results: action.payload,
        fetching: false
      })
}

const reducer = (state=initialState, action) => {
    const handler = cases[action.type]
    return handler ? handler(state, action):state
}
