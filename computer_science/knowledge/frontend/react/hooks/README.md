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

