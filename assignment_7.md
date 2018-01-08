## 課題 7

このページに含まれる全ノードのうち id 属性がついているものはいくつありますか？ 必要であれば Element.getAttribute() を参照してください。

## 回答

20

```js
function countNodesWithIds(parent, count = 0) {
  if (parent.hasChildNodes()) {
    for (let node = parent.firstChild; node; node = node.nextSibling) {
      if (node.hasAttribute && node.hasAttribute('id')) count++;
      count = countNodesWithIds(node, count);
    }
  }
  return count;
}

console.log(countNodesWithIds(document))
```
