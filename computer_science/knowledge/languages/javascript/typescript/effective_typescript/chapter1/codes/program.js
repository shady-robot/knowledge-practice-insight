var __extends = (this && this.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (Object.prototype.hasOwnProperty.call(b, p)) d[p] = b[p]; };
        return extendStatics(d, b);
    };
    return function (d, b) {
        if (typeof b !== "function" && b !== null)
            throw new TypeError("Class extends value " + String(b) + " is not a constructor or null");
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
function add(a, b) {
    return a + b;
}
console.log(add(10, null));
var states = [
    { name: 'Alabama', capital: 'Montgomery' },
    { name: "China", capital: "Beijing" }
];
for (var _i = 0, states_1 = states; _i < states_1.length; _i++) {
    var state = states_1[_i];
    console.log(state.capital);
}
function calculateArea(shape) {
    if ("height" in shape) {
        shape;
        return shape.width * shape.height;
    }
    else {
        shape;
        return shape.width * shape.width;
    }
}
var sqaure = { width: 2 };
console.log(calculateArea(sqaure));
function calculateAreaV2(shape) {
    if (shape.kind === "rectangle") {
        shape;
        return shape.width * shape.height;
    }
    else {
        shape;
        return shape.width * shape.width;
    }
}
var squarev2 = { kind: "rectangle", height: 2, width: 3 };
console.log(calculateAreaV2(squarev2));
// Shape Version3
var SquareV3 = /** @class */ (function () {
    function SquareV3(width) {
        this.width = width;
    }
    return SquareV3;
}());
var RectangleV3 = /** @class */ (function (_super) {
    __extends(RectangleV3, _super);
    function RectangleV3(width, height) {
        var _this = _super.call(this, width) || this;
        _this.width = width;
        _this.height = height;
        return _this;
    }
    return RectangleV3;
}(SquareV3));
function calculateAreaV3(shape) {
    if (shape instanceof RectangleV3) {
        shape;
        return shape.width * shape.height;
    }
    else {
        shape;
        return shape.width * shape.width;
    }
}
var squarev3 = new SquareV3(2);
console.log(calculateAreaV3(squarev3));
