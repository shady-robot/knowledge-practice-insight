/*
 * action_creator_bind.js
 *
 */

import {bindActionCreators, createStore } from 'redux'

import rootReducer from './reducer/root'

const store = createStore(rootReducer)

const doAddToDoItem = payload => ({
    type: "TODO_ADDED", payload
})

const boundAddToDoItem = bindActionCreators(doAddToDoItem, store.dispatch)

const doRemoveToDoItem = id => ({ type: "TODO_REMOVE", payload: id})
const doClearToDos = () => ({ type: 'TODOS_CLEARED' })

const boundToDoActions = bindActionCreators(
  {
      add: doAddToDoItem,
      remove: doRemoveToDoItem,
      clear: doClearToDos
    },
  store.dispatch
)

boundToDoActions.add('see the world')
boundToDoActions.remove('23324')
boundToDoActions.clear()



