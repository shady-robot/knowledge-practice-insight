# Javascript

## Quick Test for Javascript modules

```js
const script = document.createElement('script');
script.src = 'https://cdn.jsdelivr.net/npm/dayjs@1.10.7/dayjs.min.js';
document.head.appendChild(script);

const dayjs = window.dayjs;
const date = dayjs('2022-02-14');
console.log(date.format('YYYY-MM-DD'));
```
