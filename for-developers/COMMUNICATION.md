# Communication between endpoints:

To establish communication between the various modules, endpoints and user interfaces of our application, we have declared and are using a very strict Segment.

This segment is used in all communications with very little variation and should always be regarded as valid unless specified otherwise.

The segment consists of the following (mandatory) fields, but can and is amended for each communication to meed its needs. For specifics please lookup the corresponding module documentation.

Segment:

<ul>
    <li> 
        token -> oauth2 token for verification - if this is missing the message is automatically and immediatelly dropped in all endpoints
    </li>
    <li> 
        data -> application level data, managed and set by user - this is expected to be one of the following
            <ul>
                <li>
                    binary data such as base64 encoded strings
                </li>
                <li>
                    json object
                </li>
            </ul>
    </li>
    Since it is implemented on application level, the developer is responsible for the parsing of the data, hence the format can be pretty much anything, BUT for maintenance purposes PLEASE use one of the above!
</ul>

<h3>
<b>
NOTE:
</b>
</h3>
<b>
The whole segment will be base64 encoded, so you will NOT have to worry about being URL/binary safe!
</b>