## 課題 9

このページには id が重複しているノードがあるでしょうか？

## 回答

```js
const elementIdMap = new Map;
let hasDuplicatedIds = false;

const findDuplicatedIds = root => {
  if (root.hasAttribute && root.hasAttribute('id')) {
    const key = root.getAttribute('id');
    elementIdMap.set(root.getAttribute('id'), root);
    if (elementIdMap.has(key)) {
      hasDuplicatedIds = true;
    }
  }

  for (let node = root.firstChild; node; node = node.nextSibling) {
    findDuplicatedIds(node);
  }

  return hasDuplicatedIds;
}
```
