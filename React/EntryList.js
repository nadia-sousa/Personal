import React, {useContext} from 'react';
import Entry from './Entry';
import {EntryContext} from './EntryContext';

const EntryList = () => {
    const [entries, setEntries] = useContext(EntryContext);
    return(
        <div>
            {entries.map(ent => (
                <Entry date={ent.date} entry={ent.entry} />
            ))}
        </div>

    );
    
};

export default EntryList;