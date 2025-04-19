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

