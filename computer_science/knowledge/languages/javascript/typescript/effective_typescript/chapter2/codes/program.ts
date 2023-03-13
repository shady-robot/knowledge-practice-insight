let num:number =10;

function add(a: number, b:number):number{
  return a+b;
}

function sub(a: number, b:number) {
  return a-b;
}

function getElement(elOrId: string| HTMLElement | null): HTMLElement | null {
  if(typeof elOrId === "object"){
    return elOrId;
  }else if (elOrId === null) {
    return document.body;
  }else{
    const el = document.getElementById(elOrId);
    return el;
  }
}

/*
fetch(input: RequestInfo | URL, init?: RequestInit | undefined): Promise<Response>
*/
const response = fetch("http://example.com")

type A='A'
type AB = 'A'|'B'
const a:A = 'A';



