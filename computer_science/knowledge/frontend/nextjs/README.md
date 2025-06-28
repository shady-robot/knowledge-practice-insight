# Next.js

Next.js is a React framework for building full-stack applications. You use React
Components to build user interfaces, and Next.js for additional features and optimization.

* An intuitive page-based routing system(with support for dynamic routes)
* Pre-rendering, both static generation(SSG) and server-side rendering(SSR) are
  supported on a per-page basis
* Automatic code splitting for faster page loads
* Client-side routing with optimized prefetching
* Built-in CSS and Sass support, and support for any CSS-in-JS library.
* Development environment with Fast Refresh support
* API routes to build API endpoints with Serverless Functions
* Fully extendable

## Folder Structure

* `/app`: Contains all the routes, components, and logic for your application.
* `/app/lib`: Contains functions used in your application, such as reusable utility functions and data fetching functions.
* `/app/ui`: Contains all the UI components for your application.
* `/public`: Contains all the static assets for your application.
* `Config files`: `next.config.ts`

By having a special name for the `page` files, Next.js allows you to colocate UI components, test files, and other related code with your routes. Only the content inside the `page` file will be publicly accissble.

The layout file is the best way to create a shared layout that all pages in your application can use.

## Routing

Next.js has a file-system based router built on the concept of pages.
When a file is added to the `pages` directory can be used to define most common
patterns.

```text
pages/index.js                  ---> /
pages/blog/index.js             ---> /blog
pages/blog/first-post.js        ---> /blog/first-post

pages/blog/[slug].js            ---> /blog/:slug (/blog/hello-world)
pages/[username]/settings.js    ---> /:username/settings (/foo/settings)
pages/post/[...all].js          --->  /post/* (/post/2020/id/title)
```

### Link

The `Link` component enables client-side navigation between two pages in the
same Next.js app. Client-side navigation means that the page transition happens
using Javascript, which faster than the default navigation done by the browser.

### Code Splitting and prefetching

Next.js does code splitting automatically, so each page only loads what's
necessary for that page. That means when the homepage is rendered, the code for
other pages is not served initially. In a production build of Next.js, whenever
`Link` component appear in the browser's viewport, Next.js automatically
prefetches the code for the linked page in the background.

To improve the navigation experience, Next.js automatically code splits your application by route segments.
Splitting code by routes means that pages become isolated. If a certain page throws an error, the rest of the application will
still work.

Next.js automatically prefetches the code for the linked route in the background. By the time the user clicks the link, the code
for the destination page will already be loaded in the background, and this is what makes the page transition near-instant.

### Assets

Next.js can serve static assets, like images, under the top-level `public`
directory. Files inside `public` can be referenced from the root of the
application similar to `pages`.

#### Image Component and Image Optimization

`next/image` is an extension of the HTML `<img>` element, evolved for the modern
web. Next.js has support for image Optimization by default. This allows for
resizing, optimizing, and serving images in modern formats like `WebP` when the
browser supports it. This avoid shipping large images to devices with a smaller
viewport. It also allows Next.js to automatically adopt future image formats and
serve them to browser that support those formats.

Instead of optimizing images at build time, Next.js optimizes images on-demand,
as users request them. Images are lazy loaded by default. Images are always
rendered in such a way as to avoid Cumulative Layout Shift, a Core Web Vital
that Google is going to used in search ranking.

#### Third-Party Javascript

Third-party Javascript refers to any scripts that are added from a third-party
source. `next/script` is an extension of the HTML `<script>` element and
optimizes when additional scripts are fetched and executed.

#### CSS Styling

CSS modules allow you to locally scope CSS at the component-level by
automatically creating unique class names. This allows you to use the same CSS
class name in different files without worrying about class name collisions.

In addition to CSS modules, you can style your Next.js application in a variety
of ways, including:

* Sass which allows you to import `.css` and `.scss` files.
* PostCSS libraries like `Tailwind CSS`.
* CSS-in-JS libraries such as `styled-jsx`, `styled-components`, and `emotion`

CSS modules automatically generate unique class names. As long as you use CSS
modules, you don't have to worry about class name collisions. Nextjs's code
splitting features works on CSS Modules as well. It ensures the minimal amount
of CSS is loaded for each page. This results in smaller bundle sizes. CSS
modules are extracted from the Javascript bundles at build time and generate
`.css` files that are loaded automatically by Next.js.

##### Global Styles

To load global CSS to your application, create a file called `pages/_app.js`
with the following content:

```js
export default function APP({Component, pageProps}){
    return <Component {...pageProps}>
}
```

The default export of `_app.js` is a top-level React component that wraps all
the pages in your application. In Next.js, you can add global CSS files by
importing them from `pages/_app.js`. You cannot import global CSS anywhere else.

1. Using the `clsx` library to toggle classes.

    ```jsx
    <div
        className={clsx({
        [styles.success]: type === 'success',
        [styles.error]: type === 'error',})}
    >
    ```

2. Customizing PostCSS Config
3. Using Sass

## Server Components to fetch data

By default, Next.js applications use React Server Components. Fetching data with Server Components is a relatively new approach:

1. Server Components support Javascript Promises, providing a solution for asynchronous tasks like data fetching natively. You can use
   `sync/await` syntax without needing `useEffect`, `useState` or other data fetching libraries.
2. Server Components run on the server, so you can keep expensive data fetches and logic on the server, only sending the result to the client.
3. Since Server Components run on the server, you can query the database directly without an additional API layer. This saves you from writing
4. and maintaining additional code.

A "waterfall" refers to sequence of network requests that depend on the completion of previous requests. In the case of data fetching, each request can only
begin once the previous request has returned data.
You may want the waterfalls because you want a condition to be satisfied before you make the next request.

In Javascript, you can use the `Promise.all()` or `Promise.allSettled()` functions to initiate all promises at the same time.

```js
const data = await Promise.all([
    invoiceCountPromise,
    customerCountPromise,
    invoiceStatusPromise,
])
```

1. Start executing all data fetches at the same time, which is faster than waiting for each request to complete in waterfall.
2. Use a native Javascript pattern that can be applied to any library or framework.

### Static rendering

With static rendering, data fetching and rendering happens on the server at build time or when revalidating data.

1. Faster Websites -  Pre-rendered content can be cached and globally distributed when deployed to different host platform.
2. Reduce Server Load -  Because the content is cached, your server does not have to dynamically generate content for each user request.
3. SEO - Pre-rendered content is easier for search engine crawlers to index, as the content is already available when the page load.

### Dynamic rendering

1. Real-time data - Dynamic rendering allows your application to display real-time or frequently updated data.
2. User-specific Content - It's easier to serve personalized content.
3. Request time information - Dynamic rendering allows you to access information that can only be known at request time.

### Streaming

Streaming is a data transfer technique that allows you to break down a route into smaller "chunks" and progressively stream them from 
the server to the client as they become ready.
By streaming, you can prevent slow data requests from blocking your whole page. Streaming works well with React's component model, as each component can be considered a chunk.

`loading.tsx` is a special `Next.js` file built on top of React Suspense. It allows you to create fallback UI to show as a replacement while page content loads.

### Router group

Route groups allow you to organize files into logical groups without affecting the URL path structure. When you create a new folder using parentheses `()`, the name won't be included in the URL path.

### Streaming a component

Suspense allows you to defer rendering parts of your application until some condition is met. You can wrap your dynamic components in Suspense. Then, pass
it a fallback component to show while the dynamic component loads.

Where you place your suspense boundaries will vary depending on your application. In general, it's a good practice to move your data fetches down to the
components that need it, and then wrap those components in Suspense.

## Partial Pre-rendering

Combine static rendering, dynamic rendering, and streaming in the same route with Partial Pre-rendering(PPR).

Next.js 14 introduced an experimental version of Partial Pre-rendering - a new rendering model that allows you to combine the benefits of static and dynamic rendering in the same route.

Partial Pre-rendering uses React's Suspense to defer rendering parts of your application until some condition is met. The Suspense fallback is embedded into
the initial HTML file along with the static content. At build time, the static content is pre-rendered to create a static shell. The rendering of a dynamic content is postponed until the user requests the route.

## URL search params

1. Bookmarkable and shareable URLs.
2. Server-side rendering: URL parameters can be directly consumed on the server to render the initial state, making it easier to handle server rendering.
3. Analytics and tracking: HAving search queries and filters directly in the URL makes it easier to track user behavior without requiring additional client-side logic.

### Debouncing

Debouncing is a programming practice that limits the rate at which a function can fire. 

1. Trigger Event: When an event that should be debounced(like a keystroke in search box) occurs, a timer starts.
2. Wait: If a new event occurs before the timer expires, the timer is reset.
3. Execution: If the timer reaches the end of its countdown, the debounced function is executed.
