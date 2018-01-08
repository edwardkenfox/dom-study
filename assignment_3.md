## 課題 3

countNodes(document) の結果、得られるノード数は querySelectorAll('*').length で得られる結果と同じでしょうか？ もし大きな違いがあるならそれはなぜでしょうか？ （注: これは少し意地悪な問題です。思いつかないときは飛ばしてかまいません）

## 回答

ならない。`querySelectorAll`は与えられた文字列をCSS SelectorとしてElementの数を数えるが、childNodesは`textNode`など`querySelecotorAll('*')`にはマッチしない要素も数えるため。

```js
function countNodes(node) {
  let count = 0;
  for (let i = 0; i < node.childNodes.length; ++i) {
    ++count;
    const child = node.childNodes[i];
    count += countNodes(child);
  }
  return count;
}

var e = document.createElement('div');
e.append('text');

console.log(e.querySelectorAll('*').length)
//=> 0

console.log(countNodes(e))
//=> 1
```
