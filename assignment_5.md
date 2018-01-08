## 課題 5

countNodes() を改良しましょう。node.childNodes を使用することなく「確実に」実行時間 O(N) でツリーをトラバースする関数に修正してください。 必要に応じて Node の Web API を参照してください。

## 回答

```js
function countNodes(parent, count = 0) {
  if (parent.hasChildNodes()) {
    for (let node = parent.firstChild; node; node = node.nextSibling) {
      count = countNodes(node, count + 1);
    }
  }
  return count;
}
```
