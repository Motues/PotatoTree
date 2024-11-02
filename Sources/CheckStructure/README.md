# PotatoTree

## CheckStructure

这个模块是用来检查树结构是否符合要求，比如是否节点和边的属性是否齐全等。

决策树的结构由节点和边组成，节点记录位于当前状态应该执行的行为，边记录当前节点和下一个节点之间的转移条件。

### 树结构的存储

树结构将保持在JSON文件中，格式如下。

```json
{
  "tree": {
    "name": "root",
    "id": 0,
    "attribute" : {},
    "children": [],
    "edges": []
  }
}
```

节点属性由节点名称`name`、节点编号`id`、节点属性`attributes`、子节点`children`和边`edges`组成。

* 子节点`children`为**数组**，保存与当前节点相连的子节点；保存的子节点为**对象**，结构与根节点一致，包括节点名称、节点编号、节点属性、子节点和边等信息。
* 边`edges`为**数组**，与子节点相对应，保存连接当前节点与子节点的边信息；保存的边为**对象**，包含目标节点编号`target`和边属性`attributes`等信息。

具体示例可以参考[`Tree.json`](./Extras/Tree.json)。

### 校验文件

节点属性保存在一个`JSON`文件中，通过读取这个文件来检查树结构是否齐全。`NodeAttributes`记录节点属性，`EdgeAttributes`记录边属性，如下所示。

```json
{
  "NodeAttributes" : ["DestinationID", "FireState"],
  "EdgeAttributes" : ["AmmoLeft", "Health"]
}
```

