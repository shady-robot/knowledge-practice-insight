# Next.js

* An intuitive page-based routing system(with support for dynamic routes)
* Pre-rendering, both static generation(SSG) and server-side rendering(SSR) are
  supported on a per-page basis
* Automatic code splitting for faster page loads
* Client-side routing with optimized prefetching
* Built-in CSS and Sass support, and support for any CSS-in-JS library.
* Development environment with Fast Refresh support
* API routes to build API endpoints with Serverless Functions
* Fully extendable

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

