# React Hooks

## A glance of hooks

```js
import React, { useState } from 'react';

function Example() {
  const [ count, setCount ] = useState(0);

  return (
    <div>
      <p> You clicked { count } times</p>
      <button onClick={()=>setCount(count+1)}>Click me</button>
    </div>
  )
}
```

## Why React Hooks

* React needs a better primitive for sharing stateful logic. With Hooks, you can
  extract stateful logic from a component so it can be tested independently and
  reused. Hooks allow you to reuse stateful logic without changing your
  component hierarchy.
* Hooks let you split one component into smaller functions based on what pieces
  are related, rather than forcing a split based on lifecycle methods.
* Hooks let you use more of React's features without classes. Hooks provide
  access to imperative escape hatches and don't require you to learn complex
  functional or reactive programming techniques.

## What is React Hooks

Hooks are functions that let you "hook into" React state and lifecycle features
from function components. React provides a few built-in Hooks like `useState`.
You can also create your own Hooks to reuse stateful behavior between different
components.

## When to Use

If you write a function component and realize you need to add some state to it,
previously you had to convert it to a class. Now you can use a Hook inside the
existing function component.

## How to Use

* Only call hooks at the top level
  Don't call Hooks inside loops, conditions, or nested functions. Always use
  hooks at the top level of your React function, before any early returns. By
  following this rule, you ensure that Hooks are called in the same order each
  time a component renders.
* Only call hooks from React Functions
  * Call hooks from React components
  * Call hooks from custom hooks

Use the `eslint-plugin-react-hooks` to enforce the two rules.

Refer to [Hooks Rules](https://reactjs.org/docs/hooks-rules.html) for more.

## State Hook

`useState` returns a pair: the current state value and a function that lets you
update it. The only argument to `useState` is the initial state.

## Effect Hook

The Effect Hook, `useEffect`, adds the ability to perform side effects from a
function component.

By default, React runs the effects after every render - including the first
render. Effects may also optionally specify how to "clean up" after them by
returning a function.

```js
useEffect(() => {
    ChatAPI.subscribeToFriendStatus(props.friend.id, handleStatusChange);
    return () => {
      ChatAPI.unsubscribeToFriendStatus(props.friend.id, handleStatusChange);
    }
})
```

