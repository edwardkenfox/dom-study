## 課題 8

document.getElementById(id) に相当する JavaScript の関数 myGetElementById(root, id) を自分で作成してください。 その際、普通に JavaScript の Object をハッシュマップとして使用してもよいですが、比較的新しい API である Map を使用してもよいでしょう。

## 回答

1

```js
const elementIdMap = new Map;

const myGetElementById = (root, id) => {
  if (root.hasAttribute && root.hasAttribute('id')) {
    elementIdMap.set(root.getAttribute('id'), root);
  }

  for (let node = root.firstChild; node; node = node.nextSibling) {
    myGetElementById(node, id);
  }

  return elementIdMap.get(id);
}
```

2

```js
function myGetElementById(root, id) {
  return document.querySelector(`#${id}`);
}
```
