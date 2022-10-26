import React, {useState, useContext} from 'react';
import {EntryContext} from './EntryContext';

const AddEntry = () => {
    const [date, setDate] = useState('');
    const [entry, setEntry] = useState('');
    const [entries, setEntries] = useContext(EntryContext);

    const updateDate = e => {
        setDate(e.target.value);

    }

    const updateEntry = e => {
        setEntry(e.target.value);
    }

    const addEntry = e =>{
        e.preventDefault();
        setEntries(prevEntries => [...prevEntries, {Date: date, Entry: entry}]);
        //setEntry(entry)
    }

    return(
        <form onSubmit={addEntry}>
            <input 
                type="text" 
                name="date" 
                value={date} 
                /* onChange={e => setDate(e.target.value)}*/
                onChange={updateDate}/>
            <input 
                type="text" 
                name="entry" 
                autoComplete="off" 
                value={entry} 
                /*onChange={e => setEntry(e.target.value)}*/
                onChange={updateEntry}/>
            <button>Save Entry</button>
        </form>
    );
};

export default AddEntry;