import React from 'react';

const Entry = ({date, entry}) => {
    return(
        <div className = "entry">
            <h3>{date}</h3>
            <p>{entry}</p>
        </div>
    );
}

export default Entry;
