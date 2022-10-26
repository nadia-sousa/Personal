import React, {useContext} from 'react';
import {EntryContext} from './EntryContext';

const Nav = () => {
    const[entries, setEntry] = useContext(EntryContext);
    return(
        <nav className = "nav">
            <h3>Nadia's Journal</h3>
            <h3>List of Entries: {entries.length}</h3>
        </nav>
    );
};

export default Nav;