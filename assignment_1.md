## 課題 1

あなたが Chrome の開発者になったとしましょう。以下の DOM を操作する API:

ParentNode.append(node): node を parentNode の lastChild として追加
ChildNode.before(node): node を childNode の前 (previous として) に挿入
ChildNode.remove(): node を Tree から削除
をそれぞれどのように実装しますか？ どのノードのどのポインタの更新が必要になるでしょうか？ それぞれの API の動作はリンク先の MDN のドキュメントを参照してください。

ここでは実際に実装する必要はありません。擬似コードで十分です。

## 回答

```js
let globalId = 0;

class Node {
  constructor() {
    this.parent = this.firstChild = this.lastChild = this.prev = this.next = null;
    this.id = globalId++;
  }

  append(node) {
    node.parent = this;

    const currentLast = this.lastChild;

    if (currentLast === null) {
      this.firstChild = this.lastChild = node;
    } else {
      this.lastChild = node;
      currentLast.next = node;
      node.prev = currentLast;
    }
  }

  before(node) {
    node.parent = this.parent;

    const currentPrev = this.prev;

    if (currentPrev === null) {
      this.parent.firstChild = node;
      this.parent.lastChild = currentPrev;
      this.prev = node;
      node.next = this;
    } else {
      currentPrev.next = node;
      node.prev = currentPrev;
      node.next = this;
    }
  }

  remove() {
    if (this.prev) {
      this.prev.next = this.next;
    }
    if (this.next) {
      this.next.prev = this.prev;
    }
    if (this.parent && this.parent.firstChild === this) {
      this.parent.firstChild = this.next;
      this.next.parent = this.parent;
    }
    if (this.parent && this.parent.lastChild === this) {
      this.parent.lastChid = this.prev;
      this.prev.parent = this.parent;
    }
  }
}
```
