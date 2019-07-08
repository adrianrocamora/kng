const map1 = new Map();
console.log(map1);
const map2 = new Map([[5, 41], ["name", "Paul"], ["age", 45]]);
console.log(map2);
console.log(map2.get(5));
console.log(map2.get(8));
console.log(map2.get('name'));

//set
//get
//clear
//delete
//has

console.log();
console.log();

map2.forEach((value, key, thisMap) => {
	console.log(`${key} => ${value}`);
	console.log(thisMap === map2);
})
