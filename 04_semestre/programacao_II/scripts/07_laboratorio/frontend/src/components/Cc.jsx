import { Box, Typography } from "@mui/material";
import BasicTable from "./BasicTable";
import Header from "./Header";

function Cc({titulo}){
  return (
    <Box>

      <Typography
        variant="h1"
        align="center"
        style={{fontSize: '30px', fontFamily: 'sans-serif'}}
        sx={{color: '#00693e',}}    
      >
        <Header/>
        <br/>
        <h1>{titulo}</h1>
        <br/>
        <BasicTable/>

      </Typography>
    </Box>
  );
}

export default Cc;