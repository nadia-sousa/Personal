import React, {useState, createContext} from 'react';

export const EntryContext = createContext();

export const EntryProvider = props =>{
    const[entries, setEntries] = useState([
        {
            date: '3/23/22', 
            entry: 'It was a long day today and I cannot wait to sleep'
        },
        {
            date: '4/1/22', 
            entry: 'I felt a little sick again today, so I skipped school'
        },
        {
            date: '4/3/22', 
            entry: 'I had a rough day, I just cannot wait for summer'
        }
      ]);

    return(
        <EntryContext.Provider value={[entries, setEntries]}>
            {props.children}
        </EntryContext.Provider>
    )
}