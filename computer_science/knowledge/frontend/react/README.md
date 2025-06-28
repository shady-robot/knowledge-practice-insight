# React Basic

React creates the virtual representation of your UI in the memory, and then ReactDOM receives that and syncs your UI(and then changes to it) to the DOM. This process is called reconciliation.

1. ReactDOM is the gule between React and the DOM.
2. Reconciliation is the process of syncing the virtualDOM to the actual DOM.
3. The Virtual DOM is a representation of your UI in memory.

ReactDOM exports a function called `createRoot`. An app built with React usually has a single root element. The whole application is rendered inside the root element. So ReactDOM completely manages the roAt element.

JSX is a special syntax for React that makes it easier to represent your User Interface.
JSX is not part of your browser. You need a tool to transform it into valid Javascript.

```python
createElement(type, props, ...children)
```

The children is called rest parameters and is a Javascript feature that lets a function accept and capture any number of arguments.
JSX can represent elements with children. The third argument of React.createElement() is a rest parameter that captures all arguments passed after the second one, allowing multiple child elements.

## component

1. A React component is a function that returns a React element.
2. Components are reusable and self-contained pieces of your User Interface.
3. A function name must be in UpperCamelCase to be considered a component.
4. components promote code reuse and make your User interface easier to manage.

React decides whether a JSX tag is a Component or an Element based on the first letter of the tag name.
Components start with an uppercase letter, and Elements start with a lowercase letter.

JSX has a limitation in that you can't return multiple elements from a component. Fragements wrap multiple React elements without adding an extra element to the DOM.
