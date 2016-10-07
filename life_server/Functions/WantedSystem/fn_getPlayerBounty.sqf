/*
  File: fn_getPlayerBounty.sqf
  Description: Gets player bounty value and returns it
*/

private["_pid","_player","_query","_queryResult"];
_pid = _this select 0;
_player = _this select 1;

_query format ["SELECT wantedBounty FROM wanted WHERE active='1' AND wantedID='%1'",_pid];
_queryResult = [_query,2] call DB_fnc_asyncCall;

if(count _queryResult == 0) then { _playerBounty = 0;}
else { _playerBounty = _queryResult select 0;};

(owner _player) setVariable ["playerBounty",_playerBounty,true];


/*
params [
    ["_pid","",[""]],
    ["_object",objNull,[objNull]
];

private _query = format ["SELECT wantedBounty FROM wanted WHERE active='1' AND wantedID='%1'",_pid];
private _queryResult = [_query,2] call DB_fnc_asyncCall;

private _playerBounty = [(_queryResult select 0),0] select (_queryResult isEqualTo []);

//_playerBounty remoteExecCall ["xxx", _object];

//_object setVariable ["xxx",_playerBounty,true];

// xxx = _playerBounty;
// (owner _object) publicVariableClient "xxx";
*/
