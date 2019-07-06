
let dictA = {
	test: "asdf",
	test2: "gras",
	test3: {
		asdf: "fagrs"
	}
};
let items = ["manzana", "pera", "leche", "pollo"];
let numItems = items.length;

console.clear();

console.log("Attempting to print if assert is true");
console.assert(true, "DONE. Print if true");
console.log("Attempting to print if assert is false");
console.assert(false, "DONE. Print if false");

console.count();
console.count();

console.log(dictA);
console.dir(dictA);
console.dirxml(dictA);
console.log();

console.log(items);
console.log(numItems);

var standard_input = process.stdin;
console.log(standard_input);

standard_input.setEncoding('utf-8');

console.log("Enter your name");

standard_input.on('data', function (data) {
	//User input exit
	if (data === 'exit\n') {
		// Program exit
		console.log("User input complete, program exit.");
		process.exit();
	} else {
		// Print user input in console
		console.log('User Input Data: ' + data);
	}
});
