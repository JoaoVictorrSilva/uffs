import * as React from 'react';
import Stack from '@mui/material/Stack';
import Button from '@mui/material/Button';
import { green } from '@mui/material/colors';

export default function BasicButtons({curso}) {

  return (
    <Stack spacing={2} direction="column" marginTop={2} color={green}>
      <Button variant="contained">{curso}</Button>
    </Stack>
  );
}