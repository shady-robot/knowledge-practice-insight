# Using the Effect Hook

The Effect Hook lets you perform side effects in function components. Data
fetching, setting up a subscription, and manually changing the DOM in React
components are all examples of side effects.

```js
useEffect(() => {
  document.title = `You click ${count} times`;
});
```

If you're familiar with React class lifecycle methods, you can think of
`useEffect` Hook as `componentDidMount`, `componentDidUpdate`, and
`componentWillUnmount` combined.

## Effects Without Cleanup

To run some code after React has updated the DOM. By using the `useEffect` hook,
you tell React that your component needs to do something after render. Placing
`useEffect` inside the component lets us access the state or props variables
right from the effect.

## Effects With Cleanup

If your effect returns a function, React will run it when it is time to clean
up. Every effect may return a function that cleans up after it. React performs
the cleanup when the component unmounts.

```js
useEffect(() => {
    function handleStatusChange(status) {
      setIsOnline(status.isOnline);
    }
    ChatAPI.subscribeToFriendStatus(props.friend.id, handleStatusChange);
    // Specify how to clean up after this effect:
    return function cleanup() {
      ChatAPI.unsubscribeFromFriendStatus(props.friend.id, handleStatusChange);
    };
  });
```

## Tips Using useEffect

Hooks let us split the code based on what it is doing rather than a lifecycle
method name. React will apply every effect used by the component, in the order
they were specified.

### Optimizing Performance by Skipping Effects

Cleaning up or applying the effect after every render might create a performance
problem. You can tell React to skip applying an effect if certain values haven't
changed between re-renders.

```js
useEffect(() => {
  document.title = `You clicked ${count} times`;
}, [count]); // Only re-run the effect if count changes
```

