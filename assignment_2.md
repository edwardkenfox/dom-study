## 課題 2

以下の JavaScript の関数 countNodes は「手作業」でノードツリーをトラバースしてツリーに含まれるノードの個数を数えます。 ツリーに含まれるノード数を N とした場合、countNodes(document) は実行時間が O(N)ではなく O(N^2) 時間がかかる可能性があります。それはなぜでしょうか？ Node.childNodes の動作についてはリンク先の MDN のドキュメントを参照してください。

```javascript
function countNodes(node) {
  let count = 0;
  for (let i = 0; i < node.childNodes.length; ++i) {
    ++count;
    const child = node.childNodes[i];
    count += countNodes(child);
  }
  return count;
}

console.log(countNodes(document));
```

## 回答

`childNodes` は最新の子要素のノードリストを常に返すため、ノードツリーに含まれるノード数をNとしたとき時間計算量はO(N)となる。また`countNodes()`関数は各internalノードに対して再帰的に`childNodes`を呼ぶため、O(N^2)の時間計算量となる。
