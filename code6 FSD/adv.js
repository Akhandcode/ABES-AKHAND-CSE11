let a=[1,2,3,4,5];
for(i in a)
console.log(a[i]);
let today= new Date();
console.time("test");
for(let i=0;i<10000;i++)
{}
console.timeEnd("test");
console.group()