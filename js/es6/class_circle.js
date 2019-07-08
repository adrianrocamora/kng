class Shape {

	constructor () {
		this.otherThing = 42;
	}

	expand () {
		return 3
	}
}

class Circle extends Shape {

	constructor (radius) {
		super();
		this.radius = radius;
	}

	getArea () {
		return Math.PI * 2 * this.radius;
	}

	expand () {
		return super.expand() * Math.PI;
	}

	static createFromDiameter(diameter) {
		return new Circle(diameter / 2);
	}
}

let myShape = new Shape();
console.log(myShape);
console.log(myShape.otherThing);
console.log(myShape.expand());
console.log();

let myCircle = new Circle(10);
console.log(myCircle);
console.log(myCircle.otherThing);
console.log(myCircle.expand());
console.log();

let newCircle = Circle.createFromDiameter(10);
console.log(newCircle);
