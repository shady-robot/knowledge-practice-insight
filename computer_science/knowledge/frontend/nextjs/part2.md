# Nextjs

## Pre-fetching and Data fetching

By default, Next.js pre-renders every page. This means that Next.js generates
HTML for each page in advance, instead of having it done by client-side
Javascript. Pre-rendering can result in better performance and SEO.

Each generated HTML is associated with minimal Javascript code necessary for
that page. When a page is loaded by the browser, its Javascript code runs and
makes the page full interactive.

![next pre-rendering](./images/next-pre-rendering.jpeg)

## Difference ways of pre-rendering

* Static Generation: is the pre-rendering method that generates the HTML at
  build time. The pre-rendered HTML is then reused on each request.
* Server-side Rendering: is the pre-rendering method that genetates the HTML
  on each request.

When going to production, Static Generation will happen once, at build time, and
not on every request.

## When to use

We recommend using Static Generation whenever possible, because your page can be
built once and served by CDN, which makes it much faster than having a server
render the page on every request.

If the page shows frequently updated data, and the page content changes on every
request, use the Server-side pre-rendering instead.

## Static Generations

For pages that can be generated without fetching external data at build time.
The `next build` builds the app for production. You can use the `getStaticProps`
when you try to render the HTML with first fetching some external data.

```js
export async function getStaticProps() {
  const allPostsData = getSortedPostData();
  return {
    props: {
      allPostsData,
    },
  };
```

The `getStaticProps` only runs on the server-side. It will never run on the
client side. It won't even be included in the JS module for the browser. In
production, `getStaticProps` runs at build time. Because it's meant to be run
at build time, you won't be able to use data that's only available during
request time, such as query parameters or HTTP headers.

`getStaticProps` can only be exported from a page. You can't export it from
non-page files. One of the reasons for this restriction is that React needs to
have all the required data before the page is rendered.







