import React, { useEffect, useState } from 'react';
import Table from '@mui/material/Table';
import TableBody from '@mui/material/TableBody';
import TableCell from '@mui/material/TableCell';
import TableContainer from '@mui/material/TableContainer';
import TableHead from '@mui/material/TableHead';
import TableRow from '@mui/material/TableRow';
import Paper from '@mui/material/Paper';
import axios from 'axios';

axios.defaults.baseURL = "http://localhost:3010/";
axios.defaults.headers.common["Content-Type"] = "application/json;charset=utf-8";

export default function BasicTable() {
  const [data, setData] = useState([]);

  useEffect(() => {
    const res = axios.get("/horarios/cc");
    res.then(query => {
      setData(query.data);
    }).catch(error => {
      console.log(error);
    });
  }, []);

  // Group the data by semester
  const semesters = data.reduce((result, item) => {
    if (!result[item.semester]) {
      result[item.semester] = [];
    }
    result[item.semester].push(item);
    return result;
  }, {});

  return (
    <div>
      {Object.keys(semesters).map((semester, index) => (
        <TableContainer component={Paper} key={index} style={{ marginBottom: '20px' }}>
          <Table sx={{ minWidth: 650 }} aria-label={`semester-table-${semester}`}>
            <TableHead>
              <TableRow>
                <TableCell colSpan={7} style={{ textAlign: 'center', fontWeight: 'bold' }}>
                  {semester}
                </TableCell>
              </TableRow>
              <TableRow>
                <TableCell>Horários</TableCell>
                <TableCell align="center">Segunda</TableCell>
                <TableCell align="center">Terça</TableCell>
                <TableCell align="center">Quarta</TableCell>
                <TableCell align="center">Quinta</TableCell>
                <TableCell align="center">Sexta</TableCell>
                <TableCell align="center">Sábado</TableCell>
              </TableRow>
            </TableHead>
            <TableBody>
              {semesters[semester].map((row, rowIndex) => (
                <TableRow
                  key={rowIndex}
                  sx={{ '&:last-child td, &:last-child th': { border: 0 } }}
                >
                  <TableCell component="th" scope="row">
                    {row.hora}
                  </TableCell>
                  <TableCell align="center">{row.segunda}</TableCell>
                  <TableCell align="center">{row.terca}</TableCell>
                  <TableCell align="center">{row.quarta}</TableCell>
                  <TableCell align="center">{row.quinta}</TableCell>
                  <TableCell align="center">{row.sexta}</TableCell>
                  <TableCell align="center">{row.sabado}</TableCell>
                </TableRow>
              ))}
            </TableBody>
          </Table>
        </TableContainer>
      ))}
    </div>
  );
}
