## 課題 11

以下のような CSS セレクタマッチングを実現する関数を JavaScript で擬似的に実装してください。selector としてどのようなものが指定可能かはおまかせします。 まずは例のように タグネームの配列のみでやってみましょう。

## 回答

nodeがselectorにマッチするかどうかを判定する関数。ここでは引数として与えられる `['div', 'p', 'p']` などの配列は、CSSセレクタでいうところの `div > p > p` として解釈し、 `div p p` は考慮しない。

```js
function selectorMatch(selector, node) {
  let hasMatch = false;
  for (let i = 0, tagName = selector[selector.length - 1 - i]; i < selector.length; i++) {
    console.log(i, tagName, node, tagName.toUpperCase() === node.tagName)
    if (tagName.toUpperCase() === node.tagName) {
      if (i === selector.length - 1) hasMatch = true;
      selectorMatch(selector, node.parentNode);
    } else {
      return false;
    }
  }

  return hasMatch;
}
```
