# React Hooks

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

