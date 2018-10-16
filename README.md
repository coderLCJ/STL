STL
================
Explain
----------------
* AOJ:from 2603 to 2699;
* In the C++ standard, STL is organized into 13 header files: < algorithm >, < deque >, < function >, < iterator >, < array >, < vector >, < list >, < forward_list >, < map >, < unordered_map >, < memory >, < numeric >, < queue >, < set >, < unordered_set >, < stack > and < utility >.

Container
---------------
`序列式容器`
* 向量(vector) 连续存储的元素<vector>
* 列表(list) 由节点组成的双向链表，每个结点包含着一个元素<list>
* 双端队列(deque) 连续存储的指向不同元素的指针所组成的数组<deque>
  
`适配器容器`
* 栈(stack) 后进先出的值的排列 <stack>
* 队列(queue) 先进先出的值的排列 <queue>
* 优先队列(priority_queue) 元素的次序是由作用于所存储的值对上的某种谓词决定的的一种队列 <queue>
  
`关联式容器`
* 集合(set) 由节点组成的红黑树，每个节点都包含着一个元素，节点之间以某种作用于元素对的谓词排列，没有两个不同的元素能够拥有相同的次序 <set>
* 多重集合(multiset) 允许存在两个次序相等的元素的集合 <set>
* 映射(map) 由{键，值}对组成的集合，以某种作用于键对上的谓词排列 <map>
* 多重映射(multimap) 允许键对有相等的次序的映射 <map>

[study1](https://blog.csdn.net/piaoxuezhong/article/details/54348787)
[study2](https://blog.csdn.net/sinat_35866463/article/details/76523216)
![](http://rabc1.iteye.com/od?y=a-USi41gsgu3Nz&quoao=UguKxTJn_Yq0ickxKZgEdm&fbzmo=UxbOQgN_ryW6dnNE&kzruf=pFF6W4fJ9QkMI8XKV1WT&sf=TadVh1tPJM-8HSeufm&m=HCAy9Zj2krGw7l0NHl&rooxm=2DAxEOVYemgMCzG&uaa=E1L0mJc0IIKrDlMv0tHWd&z=5shPNjJe0CKzU9&owr=6djBLG2iE7gIhLj9k_azf6&tpkfq=rGeK5bWCCi&vmqdm=rUjOTu1AGcmLyPDHVi9257h6uI&wcio=mFHiB8vkbNR6RZRp2ylCKq3o8F&j=7JPy3quexo&lj=IO71MxhWu2tjJ&sjtj=tbmmErtjiWmNRDoEHznDMib&xyw=zDVkocTzsLM7Be&rrw=pii602yjGj5KB2hpTcNVWE&kly=OX_H0iA4WExHB&mjbh=GDdNwRpO5ycPIKEGFJpdI21&vggh=7X3X_h2voO5b4ydO2&gq=nXaSnjHBBfAH1V6PWzG&busb=jSFxey1D1ePaIzhy-TsjV-qq&gixzo=o6llW3Dqd-Va&zu=sQNMuL1b96gTnx4K&e=6XmQmVqh-WkwAM8cQVP_&hy=36Vjaw5uZt&obtkd=txmOFMXWaNhmTaCh3ANv9-j9ZV&rdmjc=4HFZ6FS3lMs3O7DZ-VJ2Jibg1&ull=FOYc_XcTme5&p=7V0PORO7YjkpuinOCaI9nZ&e=tXyciWeo47WpET&gy=myoy7KTfWcb&qm=nwDcZNZyxNnvYFVWMERhuhvKG&kze=rbYT66Q_nC9PaZWZKeqElUdaid&vtd=6uF_d0Po80&d=4Rpodei9xK&qw=ysRzyTF7A6AU3oHP1xdKonUVc1&wfokg=MAPM4isH9Y46AcsJnCgInx6y&ums=EcwtqRz0fiod&o=r__mrP_zAM7vlAoiAb_&lqlsf=j2YUZ8kqKRfsG8cTD&ko=qh5ClVnYzL-1NIcqV&acmt=oRK_31OUoWWJa3VwJsk&f=BDxtrEa8-_KXo_&orrk=G3p9LQ2CNUM3K7Lnbvxuji&wykv=HtRkD6v6o4o2Cz4nnlEGgmguG&a=I1rDp-uUxbY&w=iMcjBrt-WOw&hpvbp=T8FRUkj1SFaYXMrT8aeC5H1EH&wqfe=SgPUpfbuwNFd0DrWig)
