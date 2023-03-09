function add(a:number, b:number){
    return a + b;
}
console.log(add(10, null))

interface State {
    name: string;
    capital: string;
}

const states: State[] = [
    {name: 'Alabama', capital: 'Montgomery'},
    {name: "China", capital: "Beijing"}
]

for (const state of states){
    console.log(state.capital)
}

//const x:number = null;
//
//
// Cannot check TypeScript Types at Runtime.
// shape instanceof Rectangle
interface Square{
    width: number;
}

interface Rectangle extends Square {
    height: number;
}

type Shape = Square | Rectangle;

function calculateArea(shape: Shape){
    if("height" in shape){
        shape;
        return shape.width * shape.height
    }
    else{
        shape;
        return shape.width * shape.width
    }
}
const sqaure:Square = {width: 2};
console.log(calculateArea(sqaure))

// Shape Version2

interface SquareV2{
    kind: "square";
    width: number;
}
interface RectangleV2{
    kind: "rectangle"
    height: number;
    width: number;
}
type ShapeV2 = SquareV2 |  RectangleV2
function calculateAreaV2(shape: ShapeV2){
    if(shape.kind === "rectangle") {
        shape;
        return shape.width * shape.height;
    }else{
        shape;
        return shape.width * shape.width;
    }
}
const squarev2:ShapeV2 = {kind: "rectangle", height: 2, width: 3};
console.log(calculateAreaV2(squarev2))

// Shape Version3

class SquareV3 {
    constructor(public width: number) {}
}
class RectangleV3 extends SquareV3 {
    constructor(public width:number, public height:number){
        super(width);
    }
}
type ShapeV3 = SquareV3 | RectangleV3

function calculateAreaV3(shape: ShapeV3){
    if(shape instanceof RectangleV3) {
        shape;
        return shape.width * shape.height;
    }else{
        shape;
        return shape.width * shape.width;
    }
}

const squarev3:ShapeV3 = new SquareV3(2)
console.log(calculateAreaV3(squarev3))

// Runtime types not be the same as declared types.

function setLightSwitch(value: boolean) {
    switch(value){
        case true:
            //turnLightOn();
            console.log("Turn light on")
            break;
        case false:
            //turnLightOff();
            console.log("Turn light off")
            break;
        default:
            console.log("I'm afraid I can't do that")
    }
}

interface LightApiResponse{
    lightSwitchValue: boolean;
}

async function setLight(){
    const response = await fetch("/light")
    const result: LightApiResponse = await response.json();
    setLightSwitch(result.lightSwitchValue)
}

// Structural Typing
//
// Example of using structural typing to facilitate unit testing

interface Author {
    first: string;
    last: string;
}

// PostgresDB should be import somewhere else
interface PostgresDB {
    runQuery:  (sql:string) => any[];
    status: boolean;
}
function getAuthors(database: PostgresDB):Author[] {
    const authorRows = database.runQuery(`SELECT FIRST, LAST FROM AUTHORS`);
    return authorRows.map(row => ({first: row[0], last: row[1]}))
}

interface DB {
    runQuery: (sql:string) => any[];
}

function getAuthorsV2(database: DB): Author[] {
  const authorRows = database.runQuery(`SELECT FIRST, LAST FROM AUTHORS`);
  return authorRows.map(row => ({first: row[0], last: row[1]}));
}

/*** Test code to utilized structural types
test("getAuthor", () => {
    const author = getAuthors({
        runQuery(sql: string) {
        return [['Toni', 'Morrison'], ['Maya', 'Angelou']];}
    });
    expect(authros).toEqual([
        {first: 'Toni', last: 'Morrison'},
        {first: 'Maya', last: 'Angelou'}
    ])
})
***/

