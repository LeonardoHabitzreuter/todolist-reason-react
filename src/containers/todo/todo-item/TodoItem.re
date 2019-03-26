open TodoShared;
open Utils;
open Reasy;

cssfy("./style.scss");


let getItemClass = completed => completed ? "infos completed" : "infos";

let formatDate = createdAt => createdAt
                            |> Js.Date.fromFloat
                            |> Js.Date.toString
                            |> strfy;

/**
* Component 
*/
let component = ReasonReact.statelessComponent("TodoItem")

let make = (~task: task, ~onComplete, _children) => {
    ...component,
    render: _self => 
    
    <li className="todo-item">
        
        <div className={getItemClass(task.completed)}>
            <span className="name">{strfy(task.name)}</span>
            <span className="date">{formatDate(task.createdAt)}</span>
        </div>

        <Checkbox
            value=task.completed
            onChange={onComplete} />
    </li>
};
