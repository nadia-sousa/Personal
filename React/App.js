import React from "react";
import './App.css';
import Nav from './Nav';
import EntryList from './EntryList';
import AddEntry from './AddEntry';
import {EntryProvider} from './EntryContext';


function App(){

  return(
    <EntryProvider>
      <Nav/>
      <div className = "add">
          <AddEntry />
      </div>
      <div className = "app">
            <EntryList />
      </div>
    </EntryProvider>
  );
}

export default App;

